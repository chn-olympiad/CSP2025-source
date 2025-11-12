#include <bits/stdc++.h>
using namespace std;
bool isdou(int i){
	if (i%2==0){
		return true;
	}
	return false;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
	cin>>n>>m;
	int xiaoming;
	int a=0;
	int score[101]={0};
	int paiming[101]={0};
	for(int i=0;i<n*m;i++){
		cin>>score[i];
		paiming[score[i]]=1;		
	}	
	xiaoming=score[0];
	for(int i=0;i<=100;i++){
		if(paiming[i]!=0){
			a++;	
		}
		if(i==xiaoming){
			break;
		}
	}
	cout<<a;
	a=n*m-a;
	m=a/n;
	int b=a/n;
	if(a%n==0){
		if(b%2!=0){
			n=1;
		}
	}else{
		m++;
		n=a%n;
	}
	cout<<n<< ' ' <<m;

	
	
	
	
	
	

    return 0;
}


