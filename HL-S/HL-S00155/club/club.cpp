#include <bits/stdc++.h>

using namespace std;


struct pp{
	int x;
	int y;
	int d;
};
pp a[300],b[300],c[300];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int aaa[10];
	int t,n;
	cin >> t;
	int rr=0;
	while(t){
		cin >> n;
		int ans;
		int h,p,o;
		int r=1;
		for(int i=0;i<n;i++){
			cin >> a[i].x >>  b[i].x >> c[i].x;
			a[i].y=r;
			b[i].y=r;
			c[i].y=r;
			r++;
			if(a[i].x>b[i].x&&b[i].x>c[i].x){
				a[i].d=1;
				b[i].d=2;
				c[i].d=3;
			}
			if(a[i].x>c[i].x&&c[i].x>b[i].x){
				a[i].d=1;
				b[i].d=3;
				c[i].d=2;
			}
			if(b[i].x>a[i].x&&a[i].x>c[i].x){
				a[i].d=2;
				b[i].d=1;
				c[i].d=3;
			}
			if(b[i].x>c[i].x&&c[i].x>a[i].x){
				a[i].d=3;
				b[i].d=1;
				c[i].d=2;
			}
			if(c[i].x>a[i].x&&a[i].x>b[i].x){
				a[i].d=2;
				b[i].d=3;
				c[i].d=1;
			}
			if(c[i].x>b[i].x&&b[i].x>a[i].x){
				a[i].d=3;
				b[i].d=2;
				c[i].d=1;
			}
			if(a[i].x==b[i].x&&c[i].x>a[i].x){
				a[i].d=2;
				b[i].d=2;
				c[i].d=1;
			}
			if(a[i].x==b[i].x&&c[i].x<a[i].x){
				a[i].d=1;
				b[i].d=1;
				c[i].d=3;
			}
			if(a[i].x==c[i].x&&b[i].x>a[i].x){
				a[i].d=2;
				b[i].d=1;
				c[i].d=2;
			}
			if(a[i].x==c[i].x&&b[i].x<a[i].x){
				a[i].d=1;
				b[i].d=3;
				c[i].d=1;
			}
			if(b[i].x==c[i].x&&a[i].x>b[i].x){
				a[i].d=1;
				b[i].d=2;
				c[i].d=2;
			}
			if(b[i].x==c[i].x&&a[i].x<b[i].x){
				a[i].d=3;
				b[i].d=1;
				c[i].d=1;
			}
			if(b[i].x==c[i].x&&a[i].x==b[i].x){
				a[i].d=1;
				b[i].d=1;
				c[i].d=1;
			}
		}
		for(int i=0;i<n;i++){
			int g=0;
			for(int j=0;j<n;j++){
				if(a[g].x<a[j].x){
					swap(a[g].x,a[j].x);
					swap(a[g].y,a[j].y);
					swap(a[g].d,a[j].d);
				}
				if(a[g].x==a[j].x && a[g].y>a[j].y){
					swap(a[g].y,a[j].y);
					swap(a[g].d,a[j].d);
				}
				if(b[g].x<b[j].x){
					swap(b[g].x,b[j].x);
					swap(b[g].y,b[j].y);
					swap(b[g].d,b[j].d);
				}
				if(b[g].x==b[j].x && b[g].y>b[j].y){
					swap(b[g].y,b[j].y);
					swap(b[g].d,b[j].d);
				}
				if(c[g].x<c[j].x){
					swap(c[g].x,c[j].x);
					swap(c[g].y,c[j].y);
					swap(c[g].d,c[j].d);
				}
				if(c[g].x==c[j].x && c[g].y>c[j].y){
					swap(c[g].y,c[j].y);
					swap(c[g].d,c[j].d);
				}
				g++;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i].d==1){
					if(a[i].d==b[j].d){
						swap(b[i].x,b[j].x);
						swap(b[i].y,b[j].y);
						swap(b[i].d,b[j].d);
					}
					if(a[i].d==c[j].d){
						swap(c[i].x,c[j].x);
						swap(c[i].y,c[j].y);
						swap(c[i].d,c[j].d);
					}
				}
				if(b[i].d==1){
					if(a[i].d==b[j].d){
						swap(a[i].x,a[j].x);
						swap(a[i].y,a[j].y);
						swap(a[i].d,a[j].d);
					}
					if(c[i].d==b[j].d){
						swap(c[i].x,c[j].x);
						swap(c[i].y,c[j].y);
						swap(c[i].d,c[j].d);
					}
				}
				if(c[i].d==1){
					if(c[i].d==b[j].d){
						swap(b[i].x,b[j].x);
						swap(b[i].y,b[j].y);
						swap(b[i].d,b[j].d);
					}
					if(a[i].d==c[j].d){
						swap(a[i].x,a[j].x);
						swap(a[i].y,a[j].y);
						swap(a[i].d,a[j].d);
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			if(a[i].d==1){
				if( h<n/2 || h==n/2){
					h++;
					ans+=a[i].x;
				}
			}
			if(b[i].d==1){
				if( p<n/2 || p==n/2){
					p++;
					ans+=b[i].x;
				}
			}
			if(c[i].d==1){
				if( o<n/2 || o==n/2){
					o++;
					ans+=c[i].x;
				}
			}
		}
		aaa[rr]=ans;
		rr++;
		t--;
	}
	for(int i=0;i<t;i++){
		cout << aaa[i] << endl;
	}
	return 0;
}
