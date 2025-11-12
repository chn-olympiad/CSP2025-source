#include "bits/stdc++.h"
using namespace std;
/*
4 2
2 1 0 3
* 
4 3
2 1 0 3

4 0
2 1 0 3
 */
int n,k,a[50005]={ },b[50005]={ },size=0;
vector <int> path_num;
bool path[5000][5000]={ };
bool cmd(int a,int b){
	return a>b;
}
void xor1(bool used[],int i,int ans){
    if(i>=n){  
		//cout<<i<<endl;
        path_num.push_back(ans);
        return;
    }
    for(int j=i;j<=n;j++){
        if(path[i][j]==1){
            //cout<<i<<" "<<j<<endl;
            bool pd=1;
            for(int k=i;k<=j;k++){
                if(used[k]==1){
                    pd=0;
                    //cout<<1<<endl;
                    break;
                }    
            }
            if(pd){
                for(int k=i;k<=j;k++){
                    used[k]=1;
                }
            }
            //cout<<2<<endl;
            xor1(used,j+1,ans+1);
            for(int k=i;k<=j;k++){
                used[k]=0;
            }
        }
    }  
    xor1(used,i+1,ans);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
        b[i]=b[i-1]^a[i];
        //cout<<b[i]<<" ";
    }
    //cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[j]-b[i-1]==k||b[j]-b[i-1]==-k){     
                path[i][j]=1;
                //cout<<j<<" "<<i<<" "<<b[j]<<" "<<b[i]<<endl;
                size++;
            }
        }
    }
    bool used[50005]={ };
    xor1(used,1,0);
    sort(path_num.begin(),path_num.end(),cmd);
    cout<<path_num[0];
    return 0;
}
