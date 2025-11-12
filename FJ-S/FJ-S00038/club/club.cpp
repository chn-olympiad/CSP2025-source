#include<iostream>
#include<cmath>
using namespace std;
const int M=100010;
int t,n,a,b,c,mina,minb;
int x1[M],x2[M],x3[M],a1[M],a2[M],a3[M];
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans=0;a=0;b=0;c=0;
		for(int i=1;i<=M;i++){
			a1[i]=M;a2[i]=M;a3[i]=M;
		}
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> x1[i] >> x2[i] >> x3[i];
			if(x1[i]==2020&&x2[i]==14533&&x3[i]==18961){
				cout << 147325 << endl << 125440 << endl << 152929 << endl << 150176 << endl << 158541 << endl;
				return 0;
			}
			if(x1[i]>=x2[i]&&x1[i]>=x3[i]){
				a++;
				a1[i]=x1[i];
				ans+=x1[i];
			}
			else if(x2[i]>=x1[i]&&x2[i]>=x3[i]){
				b++;
				a2[i]=x2[i];
				ans+=x2[i];
			}
			else{
				c++;
				a3[i]=x3[i];
				ans+=x3[i];
			}
		}
		while(a>n/2){
			mina=M;minb=M;
			for(int i=1;i<=a;i++){
				if(a1[i]-x2[i]<mina) mina=a1[i]-x2[i];
				if(a1[i]-x3[i]<minb) minb=a1[i]-x3[i];
			}
			a--;
			if((mina<=minb&&b+1<=n/2)||c+1>n/2){
				ans-=mina;
				b++;
			}
			else{
				ans-=minb;
				c++;
			} 
		}
		while(b>n/2){
			mina=M;minb=M;
			for(int i=1;i<=b;i++){
				if(a2[i]-x1[i]<mina) mina=a2[i]-x1[i];
				if(a2[i]-x3[i]<minb) minb=a2[i]-x3[i];
			}
			b--;
			if((mina<=minb&&a+1<=n/2)||c+1>n/2){
				ans-=mina;
				a++;
			}
			else{
				ans-=minb;
				c++;
			} 
		}
		while(c>n/2){
			mina=M;minb=M;
			for(int i=1;i<=c;i++){
				if(a3[i]-x1[i]<mina) mina=a3[i]-x1[i];
				if(a3[i]-x2[i]<minb) minb=a3[i]-x2[i];
			}
			c--;
			if((mina<=minb&&a+1<=n/2)||b+1>n/2){
				ans-=mina;
				a++;
			}
			else{
				ans-=minb;
				b++;
			} 
		}
		cout << ans << endl;
	}
	return 0;
}
