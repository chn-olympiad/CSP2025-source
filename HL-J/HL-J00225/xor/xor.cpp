#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int n,k,sum = 0,y = -1;
void jisuan(int z){
    for(int i = z;i<n;i++){
        if(i>y){
            for(int j = i;j<n;j++){
                int v = a[i];
                for(int x = i+1;x<=j;x++){
                    v = (v xor a[j]);
                }
                if(v==k){
                    sum++;
                    y = j;
                    continue;
                }
            }
        }
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
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
