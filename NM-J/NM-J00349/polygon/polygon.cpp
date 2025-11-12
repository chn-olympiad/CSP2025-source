#include <bits/stdc++.h>

using namespace std;
int n;
int A[6000]={0};
long long num=0;
long long add=0;
void Dfs(int B){
    for(int i=B;i<n;i++){
        add+=A[i];
        Dfs(i+1);
        if(add>A[i]*2){
        	num++;
        	num%998244353;
		}
        add-=A[i];
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    sort(A,A+n-1);
    Dfs(0);
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
