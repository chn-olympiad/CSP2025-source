#include <iostream>
#include <cstring>
using namespace std;

int a;
int vis[5091];
int cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>a;
	for (int i=1;i<=a;i++){
        cin>>vis[i];
	}
	for (int i=1;i<=a;i++){
        for(int j=i+1;j<=a;j++){
            if (vis[j]<vis[i]){
                swap(vis[j],vis[i]);
            }
        }
	}
	for (int i=3;i<=a;i++){
        for (int j=i-1;j>=1;j--){
            for (int k=j-1;k>=1;k--){
                if (vis[k]+vis[j]>vis[i]){
                    cnt+=(k-1)*(k-2)+1;
                }
            }
        }

	}
	cout<<cnt<<endl;
	return 0;

}

