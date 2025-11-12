#include <bits/stdc++.h>
using namespace std;
int r;
bool cmp(int x,int y){
    return x>y;

}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int l,h,human[1010];
	cin>>l>>h;
	int x=l*h;

	for(int i=0;i<x;i++){
        cin>>human[i];
        if(i==0)r=human[i];
	}
	sort(human,human+x-1,cmp);


	int sum=0;
	for(int i=0;i<l;i++){

	     for(int j=0;j<h;j++){
             if(human[sum]==r){
                cout<<i+1<<" "<<j+1;
                return 0;
             }
             sum++;
 	     }
	}
    return 0;
}
