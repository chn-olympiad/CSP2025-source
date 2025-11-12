#include<bits/stdc++.h>
using namespace std;
int ans[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int dp,w=1;
	cin>>dp;
	while(w<=dp){
		int n,t[4][100001]={0},x[100001]={0},y[100001]={0},z[100001]={0};
		int a=0,b=0,c=0,m=0;
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=1;j<=3;j++)
                cin>>t[j][i];
        for(int i=0;i<n;i++){
            m=0;
            for(int p=1;p<=3;p++) m=max(m,t[p][i]);
            if(m==t[1][i]){
                if(a+1<=n/2){
                    x[a]=m;
                    a++;
                }
                else{
                    for(int q=0;i<=a;i++)
                    if(m>x[q]){
                        x[q]=m;
                        break;
                    }
                }
            }
            else if(m==t[2][i]){
                if(b+1<=n/2){
                    y[b]=m;
                    b++;
                }
                else{
                    for(int q=0;q<=b;q++)
                    if(m>y[q]){
                        y[q]=m;
                        break;
                    }
                }
            }
            else if(m==t[3][i]){
                if(c+1<=n/2){
                    z[c]=m;
                    c++;
                }
                else{
                    for(int q=0;q<=c;q++)
                    if(m>z[q]){
                        z[q]=m;
                        break;
                    }
                }
            }
        }
        for(int n=0;n<max(a,max(b,c));n++){
            ans[w]+=x[n]+y[n]+z[n];
        }
        w++;
    }
    for(int i=1;i<=dp;i++) cout<<ans[i]<<endl;
	return 0;
}
