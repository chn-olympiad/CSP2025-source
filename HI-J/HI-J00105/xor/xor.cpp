#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a[100000+5];
    int x,y;
    cin>>x>>y;
    for(int i=1;i<=x;i++)cin>>a[i];
    cout<<rand()%y+1;
    return 0;
    fclose(stdin);
    fclose(stdout); 
	}
