#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],a1,b1,c1,ans,ans1,a2,b2,c2,a3,b3,c3,d;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,n;
	cin >>t;
	while(t--){
		cin >>n;
		for(int i=0;i<n;i++){
			cin >>a[i]>>b[i]>>c[i];
			if(a[i]>=c[i]&&a[i]>=b[i]&&a1<n/2){
				a1++;
				ans+=a[i];
			}else if(b[i]>=c[i]&&b[i]>=a[i]&&b1<n/2){
				b1++;
				ans+=b[i];
			}else if(c[i]>=b[i]&&c[i]>=a[i]&&c1<n/2){
				c1++;
				ans+=c[i];
			}
		}
		a1=0;
		b1=0;
		c1=0;
		for(int j=0;j<n/3+1;j++){
			for(int i=0;i<n;i++){
				if(a[i]>a2){
					a2=a[i];
					a3=i;
				}
				if(b[i]>b2){
					b2=b[i];
					b3=i;
				}
				if(c[i]>c2){
					c2=c[i];
					c3=i;
				}
			}
			if(a2==0&&b2==0&&c2==0){
				break;
			}
			if(d>=n){
				break;
			}
			if(a3!=b3&&a3!=c3&&a1<n/2){
				ans1+=a2;
				a[a3]=0;
				b[b3]=0;
				c[c3]=0;
				a1++;
				d++;
			}else if(a3==b3){
				if(a[a3]!=0&&b[b3]!=0&&c[c3]!=0){
					if(a2>b2){
						ans1+=a2;
						a[a3]=0;
						b[b3]=0;
						c[c3]=0;
						a1++;
						d++;
					}else{
						ans1+=b2;
						a[a3]=0;
						b[b3]=0;
						c[c3]=0;
						b2++;
						d++;
					}
				}
			}else if(a3==c3){
				if(a[a3]!=0&&b[b3]!=0&&c[c3]!=0){
					if(a2>c2){
						ans1+=a2;
						a[a3]=0;
						b[b3]=0;
						c[c3]=0;
						a1++;
						d++;
					}else{
						ans1+=c2;
						a[a3]=0;
						b[b3]=0;
						c[c3]=0;
						c2++;
						d++;
					}
				}
			}else if(a1>=n/2){
				if(b2>c2&&b1<n/2){
					ans1+=b2;
					a[a3]=0;
					b[b3]=0;
					c[c3]=0;
					b1++;
					d++;
				}else if(b2<=c2&&c1<n/2){
					ans1+=c2;
					a[a3]=0;
					b[b3]=0;
					c[c3]=0;
					c2++;
					d++;
				}
			}
			if(d>=n){
				break;
			}
			if(a1>=n/2&&b1>=n/2&&c1>=n/2){
				break;
			}
			if(a3!=b3&&b3!=c3&&b1<n/2){
				ans1+=b2;
				a[a3]=0;
				b[b3]=0;
				c[c3]=0;
				b1++;
				d++;
			}else if(a3==b3){
				if(a[a3]!=0&&b[b3]!=0&&c[c3]!=0){
					if(a2>b2){
						ans1+=a2;
						a[a3]=0;
						b[b3]=0;
						c[c3]=0;
						a1++;
						d++;
					}else{
						ans1+=b2;
						a[a3]=0;
						b[b3]=0;
						c[c3]=0;
						b2++;
						d++;
					}
				}
			}else if(b3==c3){
				if(a[a3]!=0&&b[b3]!=0&&c[c3]!=0){
					if(b2>c2){
						ans1+=b2;
						a[a3]=0;
						b[b3]=0;
						c[c3]=0;
						b1++;
						d++;
					}else{
						ans1+=c2;
						a[a3]=0;
						b[b3]=0;
						c[c3]=0;
						c2++;
						d++;
					}
				}
			}else if(b1>=n/2){
				if(a[a3]!=0&&b[b3]!=0&&c[c3]!=0){
					if(a2>c2&&b1<n/2){
						ans1+=a2;
						a[a3]=0;
						b[b3]=0;
						c[c3]=0;
						a1++;
						d++;
					}else if(b2>=c2&&c1<n/2){
						ans1+=c2;
						a[a3]=0;
						b[b3]=0;
						c[c3]=0;
						c2++;
						d++;
					}
				}
			}
			if(d>=n){
				break;
			}
			if(a1>=n/2&&b1>=n/2&&c1>=n/2){
				break;
			}
			if(a3!=b3&&a3!=c3&&a1<n/2){
				ans1+=c2;
				a[a3]=0;
				b[b3]=0;
				c[c3]=0;
				c1++;
				d++;
			}else if(c3==b3){
				if(a[a3]!=0&&b[b3]!=0&&c[c3]!=0){
					if(c2>b2){
						ans1+=c2;
						a[a3]=0;
						b[b3]=0;
						c[c3]=0;
						c1++;
						d++;
					}else{
						ans1+=b2;
						a[a3]=0;
						b[b3]=0;
						c[c3]=0;
						b2++;
						d++;
					}
				}
			}else if(a3==c3){
				if(a[a3]!=0&&b[b3]!=0&&c[c3]!=0){
					if(a2>c2){
						ans1+=a2;
						a[a3]=0;
						b[b3]=0;
						c[c3]=0;
						a1++;
						d++;
					}else{
						ans1+=c2;
						a[a3]=0;
						b[b3]=0;
						c[c3]=0;
						c2++;
						d++;
					}
				}
			}else if(c1>=n/2){
				if(b2>a2&&b1<n/2){
					ans1+=b2;
					a[a3]=0;
					b[b3]=0;
					c[c3]=0;
					b1++;
					d++;
				}else if(b2<=a2&&a1<n/2){
					ans1+=a2;
					a[a3]=0;
					b[b3]=0;
					c[c3]=0;
					a2++;
					d++;
				}
			}
			if(d>=n){
				break;
			}
			if(a1>=n/2&&b1>=n/2&&c1>=n/2){
				break;
			}
		}
		cout <<max(ans,ans1)<<endl;
		a[100005]={0};
		b[100005]={0};
		c[100005]={0};
		a1=0,b1=0,c1=0,ans=0,ans1=0,a2=0,b2=0,c2=0,a3=0,b3=0,c3=0,d=0;
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
