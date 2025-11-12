#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,j;
cin >> n >> m;
vector<int> tmp;
for(int i=0;i<m*n;i++){
    int t;
    cin >> t;
    tmp.push_back(t);
}
j = tmp[0];
sort(tmp.begin(),tmp.end());
for(int i=0;i<tmp.size();i++){
    if(tmp[i] == j){
        cout << i%n+1 << ' ' << i/n+1;
    }
}
fclose(stdin);
fclose(stdout);

return 0;
}
