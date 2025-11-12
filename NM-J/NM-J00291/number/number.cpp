#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	char s[100000];
	int s0[100000],n,size=0,num[100000];
	cin>>s;
	for(int i=0;i<100000;i++){
		if(s[i]>='0'&&s[i]<='9'){
			s0[size]=int(s[i]-48);size++;
		}
	}
	int max=-1;
	for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
			if(s0[j]>max)max=s0[j];
		}
		for(int j=0;j<size;j++){
			if(s0[j]==max){
				s0[j]=0;num[i]=max;max=-1;
			}
		}
	}
	for(int i=0;i<size;i++){
		cout<<num[i];
	}

	return 0;
}
