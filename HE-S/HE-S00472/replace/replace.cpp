#include<bits/stdc++.h>
using namespace std;
int T,n,ans=0,ans1=0;
struct A{
	int man,r,b,r1=0;
}a[300310];
int b[5];
bool cmp(A a,A b){
	return a.man>b.man;
}
void fun(int i,int ans,int n){
	if(n==0){                                                                                                                                   
		ans1=max(ans1,ans);
		return;
	}
	if(a[i].r1!=-1&&b[a[i].b]+1<=n/2){
		a[i].r1=-1;
		b[a[i].b]++;
		fun(i++,ans+=a[i].man,n--);
	}
//	fun(i++,ans,n);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		ans1=0;
		cin>>n;
		int i1=1;
		for(int i=1;i<=n*3;){
			for(int j=1;j<=3;j++){			
				cin>>a[i].man;
				a[i].r=i1;
				a[i].b=j;
				i++;
			}	
			i1++;
		}
		
		sort(a+1,a+n*3+1,cmp);
		fun(1,0,n);
		cout<<ans1<<endl;
	}
	
	return 0;
} 
