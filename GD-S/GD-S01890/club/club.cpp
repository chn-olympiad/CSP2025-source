#include<bits/stdc++.h>
const int N = 1e5+10;
using namespace std;
int n;
struct peo{
	int a1,a2,a3,vit;
}a[N];
int f[210][210][210];
//人杰地灵 上善若水 
bool cmp1(peo x,peo y){ return x.a1>y.a1; }
bool cmp2(peo x,peo y){ return x.a2-x.a1 > y.a2-y.a1; }
bool cmp3(peo x,peo y){ return max(x.a2,x.a3)-x.a1 > max(y.a2,y.a3)-y.a1; }
bool cmp4(peo x,peo y){ return max(x.a1,x.a3)-x.a2 > max(y.a1,y.a3)-y.a2; }
bool cmp5(peo x,peo y){ return max(x.a1,x.a2)-x.a3 > max(y.a1,y.a2)-y.a3; }

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.sync_with_stdio(false),cin.tie(0); 
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		if(n<=200){ // This is 50 pts  O(n^3) n<=200 
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++){
				for(int j=0;j<=i;j++){
					for(int k=0;k<=i;k++){
						int p=i-j-k;
						if(p<0) continue;
						if(j>0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i].a1);
						if(k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].a2);
						if(p>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].a3);
					}
				}
			}
			int ans=INT_MIN;
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					int p=n-i-j;
					if(p>n/2) continue;
					ans=max(ans,f[n][i][j]);				
				}
			}
			cout<<ans<<endl;
			continue;
		}
		
		int sum1,sum2,sum3; 
		int ans=0;
		sum1=sum2=sum3=0;
		for(int i=1;i<=n;i++){
			if(a[i].a2>a[i].a1){
				a[i].vit=2,sum2++,ans+=a[i].a2;
				if(a[i].a3>a[i].a2) 
					a[i].vit=3,sum3++,sum2--,ans+=a[i].a3-a[i].a2;
			}
			else{
				a[i].vit=1,sum1++,ans+=a[i].a1;
				if(a[i].a3>a[i].a1) 
					a[i].vit=3,sum3++,sum1--,ans+=a[i].a3-a[i].a1;
			} 
		}
//		cout<<sum1<<" "<<sum2<<" "<<sum3<<" ans="<<ans<<endl;
		if(sum1<=n/2&&sum2<=n/2&&sum3<=n/2){// 10 pts
//			cout<<"!";
			cout<<ans<<endl;
			continue;
		}
		if(sum1>n/2){// 5 pts
//			cout<<"-"<<endl;
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n&&sum1>n/2;i++){
				if(a[i].vit!=1) continue;
				if(a[i].a2>a[i].a3){
					if(sum2+1<=n/2)
						ans+=a[i].a2-a[i].a1,sum2++;
					else {
						ans+=a[i].a3-a[i].a1,sum3++;				
					}
				}
				else{
					if(sum3+1<=n/2)
						ans+=a[i].a3-a[i].a1,sum3++;		
					else{
						ans+=a[i].a2-a[i].a1,sum2++;
					}
				}
				sum1--;
			}
		}
		if(sum2>n/2){// 5 pts
//			cout<<"-"<<endl;
			sort(a+1,a+n+1,cmp4);
			for(int i=1;i<=n&&sum2>n/2;i++){
				if(a[i].vit!=2) continue;
				if(a[i].a1>a[i].a3){
					if(sum1+1<=n/2)
						ans+=a[i].a1-a[i].a2,sum1++;
					else {
						ans+=a[i].a3-a[i].a2,sum3++;				
					}
				}
				else{
					if(sum3+1<=n/2)
						ans+=a[i].a3-a[i].a2,sum3++;		
					else{
						ans+=a[i].a1-a[i].a2,sum1++;
					}
				}
				sum2--;
			}
		}
		if(sum3>n/2){// 5 pts
//			cout<<"-"<<endl;
			sort(a+1,a+n+1,cmp5);
			for(int i=1;i<=n&&sum3>n/2;i++){
				if(a[i].vit!=3) continue;
//				cout<<a[i].vit<<" "<<a[i].a1<<" "<<a[i].a2<<endl;
				sum3--;
				ans-=a[i].a3;
				if(a[i].a1>a[i].a2){
					if(sum1+1<=n/2)
						ans+=a[i].a1,sum1++;
					else 
						ans+=a[i].a2,sum2++;
				}
				else{
					if(sum2+1<=n/2)
						ans+=a[i].a2,sum2++;		
					else
						ans+=a[i].a1,sum1++;
				}
			}
		}
//		cout<<sum1<<" "<<sum2<<" "<<sum3<<endl;
//		cout<<"@";
		cout<<ans<<endl;
	}
	return 0;
}
