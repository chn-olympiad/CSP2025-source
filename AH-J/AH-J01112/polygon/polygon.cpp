#include<bits/stdc++.h>
using namespace std;

int cnt=0,n,a[5005];

void dfs(int p, int d, int m[5005]){
    if(p==n-1) return;

    int maxx=0,sum=0;
    for(int i=0; i<n; i++){
        maxx = max(maxx, m[i]);
        sum += m[i];
    }

    if(sum > 2*maxx){
        cnt++;
    }

    for(int i=p+1; i<n; i++){
        m[d+1]=a[i];
        dfs(i, d+1, m);
    }
    return;
}

int main(){
	freopen("polygon.in" ,"r" ,stdin );
	freopen("polygon.ans","w" ,stdout);

	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];

    dfs(0,0,a);

    cout << cnt;

    fclose(stdin );
    fclose(stdout);
    return 0;
}
