#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int n,sum = 0,y = -1;
void jisuan(int z){
    for(int i = z;i<n;i++){
        if(i>y){
            for(int j = i;j<n;j++){
                int v = a[i];
                int maxn = a[i];
                for(int x = i+1;x<=j;x++){
                    v += a[x];
                    if(a[x]>maxn){
                        maxn = a[x];
                    }
                }
                if(v>(2*abs(maxn)){
                    sum++;
                    y = j;
                    continue;
                }
            }
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    for(int z = 0;z<n;z++){
        jisuan(z);
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
