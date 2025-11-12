#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct node{
    int d[4], e, f, c, r;
}a[N][4];
int t, n, ans = 0, s[4];
bool cmp(node u, node v){
     return u.c>v.c;	
}
int main(){
    freopen("club.in","r",stdin); 
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
		s[1] = 0;
		s[2] = 0;
		s[3] = 0;
		ans = 0;
        cin>>n;
        for(int i = 1;i<=n;i++){
            int x, y, z, l, h, q;
            cin>>x>>y>>z;
            if(x>=y){
                if(x>=z){
                    l = 1;
                    if(y>z) h = 2, q = 3;
                    else{
                        h = 3, q = 2;
                    }
                } 
                if(x<z){
                    l = 3;
                    h = 1;
                    q = 2;
                }  
            }
            if(x<y){
                if(y>=z){
                    l = 2;
                    if(x>z) h = 1, q = 3;
                    else{
                        h = 3, q = 1;
                    }
                } 
                if(y<z){
                    l = 3;
                    h = 2;
                    q = 1;
                }  
            }
            a[++s[l]][l].d[1] = x;
            a[s[l]][l].d[2] = y;
            a[s[l]][l].d[3] = z;
            a[s[l]][l].e = h;
            a[s[l]][l].f = l;
            a[s[l]][l].r = q;
            a[s[l]][l].c = a[s[l]][l].d[a[s[l]][l].f]-a[s[l]][l].d[a[s[l]][l].e];
            ans+=a[s[l]][l].d[l];
            //cout<<a[s[l]][l].c<<" ";
            for(int j = s[l];j>=1;j--){
			    if(a[s[l]][l].c>a[j][l].c){
					swap(a[s[l]][l], a[j][l]);
				} 	
			}
		}
		///cout<<endl<<ans<<endl;
		for(int i = 1;i<=3;i++){
            if(s[i]>n/2){
				for(int j = n/2+1;j<=s[i];j++){

				   ans-=a[j][i].c;
				   int g = a[j][i].f, w = a[j][i].e;
                   a[++s[w]][w].d[1] = a[j][g].d[1];
                   a[s[w]][w].d[2] = a[j][g].d[2];
                   a[s[w]][w].d[3] = a[j][g].d[3];
                   a[s[w]][w].e = a[j][g].e;
                   a[s[w]][w].f = a[j][g].f;
                   a[s[w]][w].r = a[j][g].r;
                   a[s[w]][w].c = a[j][g].d[a[j][g].e]-a[j][g].d[a[j][g].r];
				}
			}
			//if(i == 1) cout<<ans<<" ";
		}
        cout<<ans<<endl;
    }
    return 0;
}
