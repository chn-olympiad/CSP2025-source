#include<bits/stdc++.h>
using namespace std;
int n,m;
char arr[505];
int ar[505];
bool f[505];
int ans;
void find(int day,int k,int nu){
    if(k >= m && day >= n){
    	ans++;
    	return ;
	}
    else if(n - m < nu) return ;
    for(int i = 1;i<=n;i++)
        if(f[i] == 0){
            f[i] = 1;
            if(arr[day] == '0' || nu >= ar[i])
                find(day+1,k,nu+1);
            else    find(day+1,k+1,nu);
            f[i] = 0;
        }
    return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",arr);
    for(int i = 1;i<=n;i++)
        scanf("%d",&ar[i]);
        find(0,0,0);
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
