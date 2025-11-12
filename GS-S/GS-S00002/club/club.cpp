#include<bits/stdc++.h>
using namespace std;

int t,n,maxx=0;
int a[100010][4];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        maxx=0;
        if(n==2){
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3 && j!=i;j++){
                    maxx=max(a[1][i]+a[2][j],maxx);
	            }
            }
        }else{
        	for(int i=1;i<=n;i++){
        		maxx+=max(a[i][1],max(a[i][2],a[i][3]));
			}
		}
        cout<<maxx<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
