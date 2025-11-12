#include<bits/stdc++.h> 
using namespace std;
int main()
{
freopen("seat.in","r","stdin");
freopen("seat.out","w","stdout");
int c,b,e[100000000];
cin>>c>>b;
for(int i=1;i<=c*b;i++){
	    cin>>e[i];
    }
sort(c*b+e[i],c*b+e[i+1]);

for(int i=1;i<=c*b;i++){
	    cout<<e[i];
    }
}    


