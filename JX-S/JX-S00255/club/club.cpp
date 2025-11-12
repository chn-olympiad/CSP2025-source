#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int a[maxn][maxn][5]={0};
long long count1=0,ans=0;
int a1,a2,a3;
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        a1=0;
        a2=0;
        a3=0;
        ans=0;
        int n;
        cin>>n;
        count1=n/2;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=3;k++){
				cin>>a[i][j][k];
			}
        }
        for(int j=1;j<=n;j++){
			if(a[i][j][1]>a[i][j][2]&&a[i][j][1]>a[i][j][3]){
				a1++;
				if(a3>count1||a2>count1||a1>count1){
                    int n=a[i][j][2]>a[i][j][3]? a[i][j][2]:a[i][j][3];
                    ans+=n;
                    a1--;
                }else ans+=a[i][j][1];
			}
			else if(a[i][j][2]>a[t][j][1]&&a[i][j][2]>a[i][j][3]){
				a2++;
				if(a3>count1||a2>count1||a1>count1){
                    int n=a[i][j][1]>a[i][j][3]? a[i][j][1]:a[i][j][3];
                    ans+=n;
                    a2--;
                }
				else ans+=a[i][j][2];
			}
			else if(a[i][j][3]>a[t][j][1]&&a[i][j][3]>a[i][j][2]){
				a3++;
				if(a3>count1||a2>count1||a1>count1){
                    int n=a[i][j][1]>a[i][j][2]? a[i][j][1]:a[i][j][2];
                    ans+=n;
                    a3--;
                }
				else ans+=a[i][j][3];
			}
		}
		cout<<ans<<endl;
    }
    return 0;
}
