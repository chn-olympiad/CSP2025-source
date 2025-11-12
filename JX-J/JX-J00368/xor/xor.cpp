#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5*1e5+5;
int n,k,nums[MAXN];
int xor_num(int x,int y){
	int s=nums[x];
	for(int i=x+1;i<y;++i){
		s^=nums[i];
	}
	return s;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdin);
    //wo cuo le, really zuo bu lai. When n<=2 and k=0, we can try to answer.
    int s=1;
    cin>>n>>k;
    for(int i=0;i<n;++i) cin>>nums[i];
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(xor_num(i,j)==k){
                i = j+1;
                ++s;
                break;
            }
        }
    }
    cout<<s;
    return 0;
}
