#include<bits/stdc++.h>
#define ll long long
#define N 1000010
using namespace std;
ll a[N],n,k,cnt,flag;
void init(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                if(flag==1){
                    cnt++;
                    flag=0;
                }else{
                    flag++;
                }
            }
        }
	}else{
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                cnt++;
            }
        }
	}cout<<cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	init();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
