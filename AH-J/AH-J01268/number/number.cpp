#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in", "r",stdin);
    freopen("number.out","w",stdout);
    long long s,m,i,count;
    m=0;
    int cc[1000000];
    int dd[1000000];
    cin>>s;
    if(s>=1&&s<=9){
        cout<<s;
        return 0;
    }
    int a=1;
    for(i=1;i<10000000;i++){
		count++;
		a=a*10;
		dd[i]=s%a;
		cc[i]=dd[i]-cc[i-1]; 
		a=a/10;
		cc[i]=cc[i]/a;
		a=a*10;
		if(cc[i]==0){
			break;
		}
		if(cc[i]>9){
			i--;
			break;
		}
		if(cc[i]<1){
			i--;
			break;
		}
	}
	for(int nm=1;nm<=50;nm++){
	for(i=1;i<count-1;i++){
	if(cc[i]<cc[i+1]){
	m=cc[i];
	cc[i]=cc[i+1];
	cc[i+1]=m;
	m=0;
	}
}
}
	for(i=1;i<=count-1;i++){
		cout<<cc[i];
	}
	return 0;
}
