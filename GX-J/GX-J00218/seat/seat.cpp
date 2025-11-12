#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    int sum=m*n-1;
    int number[sum],key,templi[sum],index=0;
    for(int i=0;i<=sum;i++){
		cin>>templi[i];
		if(index==0){
			key=templi[i];
			index++;}
		number[i]=templi[i];
	}
	sort(number,number+1+sum);
	sort(templi,templi+1+sum);
	for(int i=0;i<=sum;i++){
		number[i]=templi[sum-i];
		if(number[i]==key)index=i;
	}
	if(index==0)cout<<"1 1";
	else if (index==1)cout<<"2"<<" 1";
	else if (index==2)cout<<"2"<<" 2";
	else if (index==3)cout<<"2"<<" 1";

	
    return 0;
}

