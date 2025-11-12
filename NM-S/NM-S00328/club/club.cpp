#include<bits/stdc++.h>
using namespace std;
struct C{
	int y,r,s,ma,ma2,h;
};
C a[1000005];

int cmp(C a,C b){
	if(a.h==b.h){
		return a.ma>b.ma;
	}else{
		return a.h<b.h;
	}
}

int main()
{

    freopen("club.in","r".stdin);
    freopen("club.out","w".stdout);
    int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int s=n/2;
		int b[4]={};
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i].y >>a[i].r >>a[i].s;

			if(a[i].y>a[i].r&&a[i].y>a[i].s){
				a[i].ma=a[i].y;
				a[i].ma2=max(a[i].r,a[i].s);
				a[i].h=1;
				b[i]++;
			}else if(a[i].r>a[i].y&&a[i].r>a[i].s){
			    a[i].ma=a[i].r;
			    a[i].ma2=max(a[i].y,a[i].s);
				a[i].h=2;
				b[i]++;
			}else{
				a[i].ma=a[i].s;
				a[i].ma2=max(a[i].y,a[i].r);
				a[i].h=3;
				b[i]++;
			}

			ans+=a[i].ma;
		}
		sort(a,a+n,cmp);

		int j1=0,j2=0,j3=0;

		if(b[1]<=s&&b[2]<=s&&b[3]<=s){
			cout<<ans;
			continue;
		}else{
			ans=0;
			for(int i=0;i<n;i++){
				if(j1<s&&a[i].h==1){
					if(a[i].y+a[i+1].r<a[i+1].y+a[i].r){
						ans+=a[i].r;
						j2++;
					}else{
						ans+=a[i].y;
					j1++;
					}


				}else if(j2<s){
					ans+=a[i].r;
					j2++;

				}else{
					ans+=a[i].s;
					j3++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
