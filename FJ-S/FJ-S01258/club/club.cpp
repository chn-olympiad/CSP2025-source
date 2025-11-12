#include <bits/stdc++.h>
using namespace std;
long long sum=0;
long long qw[6];
int asd[100005];
int asf[100005];
int asg[100005];

struct sty{
	int d,f,g,l=0;
}z[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		sum=0;
		int n,a,b,c,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		int k=n/2;
		for(int o=1;o<=n;o++){
			cin>>asd[o]>>asf[o]>>asg[o];
			z[o].d=asd[o];
			z[o].f=asf[o];
			z[o].g=asg[o];
		}
		sort(asd+1,asd+1+n);
		sort(asf+1,asf+1+n);
		sort(asg+1,asg+1+n);
		if((n/2)%2==0){
			a=asd[n-(n-k)+1];
			b=asf[n-(n-k)+1];
			c=asg[n-(n-k)+1];
		}else{
			a=asd[n-(n-k)];
			b=asf[n-(n-k)];
			c=asg[n-(n-k)];
		}
		for(int p=1;p<=n;p++){
			if(z[p].l==0&&z[p].d>=a&&cnt1<k&&z[p].d>=z[p].f&&z[p].d>=z[p].g&&z[p].d!=0){
				sum+=z[p].d;
				z[p].d=0;
				cnt1++;
				z[p].l=1;
			}else if(z[p].l==0&&z[p].f>=b&&cnt2<k&&z[p].f>=z[p].d&&z[p].f>=z[p].g&&z[p].f!=0){
				sum+=z[p].f;
				z[p].f=0;
				cnt2++;
				z[p].l=1;
			}else if(z[p].l==0&&z[p].g>=c&&cnt3<k&&z[p].g>=z[p].f&&z[p].d<=z[p].g&&z[p].g!=0){
				sum+=z[p].g;
				cout<<z[p].g;
				z[p].g=0;
				cnt3++;
				z[p].l=1;
			}
		}
		for(int p=1;p<=n;p++){
			if(z[p].l==0&&z[p].d>=a&&cnt1<k&&z[p].d>=z[p].f&&cnt3==k&&z[p].d!=0){
				sum+=z[p].d;
				z[p].d=0;
				cnt1++;
				z[p].l=1;
			}else if(z[p].l==0&&z[p].d>=a&&cnt1<k&&z[p].d>=z[p].g&&cnt2==k&&z[p].d!=0){
				sum+=z[p].d;
				z[p].d=0;
				cnt1++;
				z[p].l=1;
			}else if(z[p].l==0&&z[p].f>=b&&cnt2<k&&z[p].f>=z[p].g&&cnt1==k&&z[p].f!=0){
				sum+=z[p].f;
				z[p].f=0;
				cnt2++;
				z[p].l=1;
			}else if(z[p].l==0&&z[p].f>=b&&cnt2<k&&z[p].f>=z[p].d&&cnt3==k&&z[p].f!=0){
				sum+=z[p].f;
				z[p].f=0;
				cnt2++;
				z[p].l=1;
			}else if(z[p].l==0&&z[p].g>=c&&cnt3<k&&z[p].f<=z[p].g&&cnt1==k&&z[p].g!=0){
				sum+=z[p].g;
				z[p].g=0;
				cnt3++;
				z[p].l=1;
			}else if(z[p].l==0&&z[p].g>=c&&cnt3<k&&z[p].d<=z[p].g&&cnt2==k&&z[p].g!=0){
				sum+=z[p].g;
				z[p].g=0;
				cnt3++;
				z[p].l=1;
			}
		}
		for(int p=1;p<=n;p++){
			if(z[p].l==0&&z[p].d>=a&&cnt2==k&&cnt3==k){
				sum+=z[p].d;
				z[p].d=0;
				cnt1++;
				z[p].l=1;
			}else if(z[p].l==0&&z[p].f>=b&&cnt3==k&&cnt1==k){
				sum+=z[p].f;
				z[p].f=0;
				cnt2++;
				z[p].l=1;
			}else if(z[p].l==0&&z[p].g>=c&&cnt2==k&&cnt1==k){
				sum+=z[p].g;
				z[p].g=0;
				cnt3++;
				z[p].l=1;
			}
		}
		qw[i]=sum;
		for(int u=1;u<=n;u++){
			z[u].l=0;
		}
	}
	for(int i=1;i<=T;i++){
		cout<<qw[i]<<endl;
	}
	return 0;
}
