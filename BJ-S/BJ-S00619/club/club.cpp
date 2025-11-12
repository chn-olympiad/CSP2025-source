#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1005],b[1005],c[1005],t,n,i,sum;
struct nd{
	int g;
	int place;
	}d[10005];

bool cmp(nd a,nd b){
    return a.g<b.g;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		sum=0;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(d,0,sizeof d);
		cin >> n;
        int aa=0,bb=0,cc=0,topd=n/2+1;
        for(i=1;i<=n;i++){
            cin >> a[i] >> b[i] >> c[i];
            if(max({a[i],b[i],c[i]})==b[i]){
                bb++;
                sum+=b[i];
                d[i].g=max(a[i]-b[i],c[i]-b[i]);
                if(a[i]>c[i]) d[i].place=21;
                else d[i].place=23;
            }
            if(max({a[i],b[i],c[i]})==a[i]){
                aa++;
                sum+=a[i];
                d[i].g=max(b[i]-a[i],c[i]-a[i]);
                if(b[i]>c[i]) d[i].place=12;
                else d[i].place=13;
            }
            if(max({a[i],b[i],c[i]})==c[i]){
                cc++;
                sum+=c[i];
                d[i].g=max(a[i]-c[i],b[i]-c[i]);
                if(a[i]>b[i]) d[i].place=31;
                else d[i].place=32;
            }

        }
//         for(i=1;i<=n;i++)
//            cout << d[i].g << " " << d[i].place << endl;
        sort(d+1,d+n+1,cmp);
        while(aa>n/2 or bb>n/2 or cc>n/2){
            sum+=d[topd].g;
            switch(d[topd].place){
                case 12:{aa--;bb++;}
                case 13:{aa--;cc++;}
                case 21:{bb--;aa++;}
                case 23:{bb--;cc++;}
                case 31:{cc--;aa++;}
                case 32:{cc--;bb++;}
            }
            topd++;
            if(topd>n) break;
        }
        cout << sum << endl;

	}
    return 0;
}
