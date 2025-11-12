#include<bits/stdc++.h>
using namespace std;
int n,m,k,x[200005],y[200005],h2[200005];
string p,q,s1[200005],s2[200005],h[200005];
map<string,int>w[200005]; 
map<string,int>a;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        string t="",t0="";
        int l=s1[i].length(),e;
        for(int j=0;j<l;j++){
            if(s1[i][j]!=s2[i][j]){
               x[i]=j-1;
               break;
            }
        }
        for(int j=l-1;j>=0;j--){
            if(s1[i][j]!=s2[i][j]){
               y[i]=l-1-j;
               e=j;
               h2[i]=e;
               break;
            }
        }
        for(int j=x[i]+1;j<=e;j++){
			t+=s1[i][j];
			t0+=s2[i][j];
		}
        w[++a[t]][t]=i;
        h[i]=t0;
    }
    while(m--){
        cin>>p>>q;
        string t="",t0="";
        int l=p.length(),u,v,e;
        for(int j=0;j<l;j++){
            if(p[j]!=q[j]){
               u=j-1;
               break;
            }
        }
        for(int j=l-1;j>=0;j--){
            if(p[j]!=q[j]){
				e=j;
               v=j+1;
               break;
            }
        }
        for(int j=u+1;j<=e;j++){
			t+=p[j];
			t0+=q[j];
		}
        int ans=0;
        for(int i=1;i<=a[t];i++){
            int f=0;
            if(h[w[i][t]]!=t0) continue;
            for(int j=u-x[i];j<=u;j++){
                if(s1[w[i][t]][j-u+x[i]]!=p[j]){
                   f=1;
                   break;
                }
            }
            if(f==1) continue;
            for(int j=v;j<=v+y[i]-1;j++){
                if(s1[w[i][t]][j-v+h2[w[i][t]]+1]!=p[j]){
                   f=1;
                   break;
                }
            }
            if(f==0){
			   	ans++;
			} 
        }
        cout<<ans<<endl;
    }
    return 0;
}
