#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long T;
long long n;
long long f[N][4];
long long op[4];
long long maxx;
int a[N];
void bl(long long ans,long s){
	int sw=s+1;
	if(s==n+1){
		maxx=max(maxx,ans);
		return ;
	} 

	if(op[1]!=0){
//	cout<<"----------"<<s<<'\n'; 
		op[1]-=1;
		ans+=f[s][1]; 
	//	cout<<"==1="<<ans<<'\n';
		bl(ans,sw);
		ans-=f[s][1];
		op[1]+=1;
	}
	if(op[2]!=0){
	//	cout<<"----------"<<s<<'\n'; 
		op[2]-=1;
		ans+=f[s][2];
	//	cout<<"==2="<<ans<<'\n'; 
		bl(ans,sw);
		ans-=f[s][2];
		++op[2];
	}
	if(op[3]!=0){
	//	cout<<"----------"<<s<<'\n'; 
		op[3]-=1;
		ans+=f[s][3];
	//	cout<<"==3="<<ans<<'\n';
		bl(ans,sw);
		ans-=f[s][3];
		++op[3] ;
	}
	return ;
}
void bl2(long long ans,long s){
	int sw=s+1;
	if(s==n+1){
		maxx=max(maxx,ans);
		return ;
	} 

	if(op[1]!=0){
//	cout<<"----------"<<s<<'\n'; 
		op[1]-=1;
		ans+=f[s][1]; 
	//	cout<<"==1="<<ans<<'\n';
		bl(ans,sw);
		ans-=f[s][1];
		op[1]+=1;
	}
	if(op[2]!=0){
	//	cout<<"----------"<<s<<'\n'; 
		op[2]-=1;
		ans+=f[s][2];
	//	cout<<"==2="<<ans<<'\n'; 
		bl(ans,sw);
		ans-=f[s][2];
		++op[2];
	}
	return ;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int sum2=0,sum3=0;
		long long sum1=0;
		maxx=0;
		cin>>n;
		memset(f,0,sizeof(f));
		op[1]=n/2,op[2]=op[1],op[3]=op[2];
		for(int i=1;i<=n;i++){
			cin>>f[i][1]>>f[i][2]>>f[i][3];
			if(f[i][2]==0) sum2+=1;
			if(f[i][3]==0) sum3+=1;
			a[i]=f[i][1];
		}
		if(sum2+sum3==2*n){
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2+1;i--){
				maxx+=a[i];
			}
			cout<<maxx;
		}else if(sum3==n){
			bl2(0,1);
			cout<<maxx<<'\n';
		}else{
			bl(0,1);
			cout<<maxx<<'\n';
		}
	}
	return 0;
} 
	
//	cin>>T;
//	while(T--){
//	}
