#include<bits/stdc++.h>
using namespace std;

const int maxnm=100;
int n,m,cnt;
int l[maxnm*maxnm+5];

int main(){
	freopen("seat.in" ,"r" ,stdin );
	freopen("seat.ans","w" ,stdout);

    cin >> n >> m;
    for(int i=0; i<n*m; i++){
        cin >> l[i];
    }

    for(int i=1; i<n*m; i++){
        if(l[i]>l[0]) cnt ++;
    }

    cout << cnt/n+1 << " " << ((cnt/n+1)%2?cnt%n+1:n-cnt%n);

    fclose(stdin );
    fclose(stdout);
    return 0;
}
