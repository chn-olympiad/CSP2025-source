# include <bits/stdc++.h>
using namespace std;
int n,t;
struct asd{
	int a,c;
};
bool asd1(asd a,asd b){
	return a.a>b.a;
}
bool asd2(asd a,asd b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=0;q<t;q++){
		cin>>n;
		asd m1[100005],m2[100005],m3[100005];
		int a1=0,a2=0,a3=0,ans=0;
		bool v[100005];
		for(int i=1;i<=n;i++){
			cin>>m1[i].a>>m2[i].a>>m3[i].a;
			m1[i].c=i;
			m2[i].c=i;
			m3[i].c=i;
			ans+=max(m1[i].a,max(m2[i].a,m3[i].a));
			if(m2[i].a!=0) a2++;
			if(m3[i].a!=0) a3++;
			if(m1[i].a!=0) a1++;
		}
		if(a1==0&&a3==0){
			ans=0;
			sort(m2+1,m2+n+1,asd1);
			for(int j=1;j<=n/2;j++){
				ans+=m2[j].a;
			}
			cout<<ans<<"\n";
		}
		else if(a2==0&&a1==0){
			ans=0;
			sort(m3+1,m3+n+1,asd1);
			for(int j=1;j<=n/2;j++){
				ans+=m3[j].a;
			}
			cout<<ans<<"\n";
		}
		else if(a2==0&&a3==0){
			ans=0;
			sort(m1+1,m1+n+1,asd1);
			for(int j=1;j<=n/2;j++){
				ans+=m1[j].a;
			}
			cout<<ans<<"\n";
		}else if(a3==0){
			sort(m1+1,m1+a1+1,asd1);
			sort(m2+1,m2+a2+1,asd2);
			int js1=1,js2=1;
			for(int j=1;j<=n;j++){
				if(a2==n/2&&a1==n/2) break;
				if(v[m1[js1].c]==1){
					for(;js1<=a1;js1++){
						if(v[m1[js1].c]==0) break;
					}
				}
				if(v[m2[js2].c]==1){
					for(;js2<=a2;js2++){
						if(v[m2[js2].c]==0) break;
					}
				}
				if(m1[js1].c!=m2[js2].c&&v[m2[js2].c]==0&&v[m1[js1].c]==0){
					if(a1<n/2){
						ans+=m1[js1].a;
						v[m1[js1].c]=1;
						js1++;
					}
					if(a2<n/2){
						ans+=m2[js2].a;
						js2++;
						v[m2[js2].c]=1;
					}
				}
				else if(m1[js1].c!=m2[js2].c){
					for(int q=js1;q<=n;q++){
						if(v[m1[q].c]==0){
							js1=q;
						}
					}
					for(int q=js2;q<=n;q++){
						if(v[m2[q].c]==0){
							js2=q;
						}
					}
					if(a1<n/2){
						ans+=m1[js1].a;
						v[m1[js1].c]=1;
						js1++;
					}
					if(a2<n/2){
						ans+=m2[js2].a;
						js2++;
						v[m2[js2].c]=1;
					}
				}
			}
			cout<<ans<<endl;
			
		}else{
			cout<<ans<<endl;
		}
		
	}
	
}
