#include<bits/stdc++.h>
using namespace std;
int n,t;
int x=0,y=0,z=0;
int s;
int p[100010];
struct{
    int f,b,c;
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
            cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].f>>a[j].b>>a[j].c;
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
                s=n/2;
                p[0]=0;
            if(max(max(a[j].f,a[j].b),a[j].c)==a[j].f){
                x++;
                if(x<=s)p[j]=a[j].f;
                else{
                    x--;
                    if(max(a[j].b,a[j].c)==a[j].b){
                        y++;
                        if(y<=s){p[j]=a[j].b;}
                        else{
                                y--;
                        p[j]=a[j].c;
                        z++;}
                    }
                }
            }
            if(max(max(a[j].f,a[j].b),a[j].c)==a[j].b){
               y++;
                if(y<=s) p[j]=a[j].b;
                else{
                    y--;
                    if(max(a[j].f,a[j].c)==a[j].f){
                        x++;
                        if(x<=s){p[j]=a[j].f;}
                        else{
                            x--;
                        p[j]=a[j].c;
                        z++;}
                    }
                }
            }
            if(max(max(a[j].f,a[j].b),a[j].c)==a[j].c){
                 z++;
                if(z<=s) p[j]=a[j].c;
                else{
                    z--;
                    if(max(a[j].f,a[j].b)==a[j].f){
                        x++;
                        if(x<=s){p[j]=a[j].f;}
                        else{
                            x--;
                        p[j]=a[j].b;
                        y++;
                    }
                }
            }
            }
            p[j]+=p[j-1];
}
}
    for(int i=1;i<=t;i++){
        for(int j=n;j<=n;j++){
            cout<<p[j]<<" ";
        }
    }
    return 0;
}
