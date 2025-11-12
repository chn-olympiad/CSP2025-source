#include<iostream> 
#include<cstdio>
#include<string>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string S1,S2;
	cin>>S1;
	for(int i=0;S1[i]!='\0';i++){
		if('0'<=S1[i]&&S1[i]<='9'){
			S2+=S1[i];
		}
	}
	int Len=S2.size();
	for(int i=0;i<Len;i++){
		for(int j=i+1;j<Len;j++){
			if(S2[i]<S2[j]){
				swap(S2[i],S2[j]);
			}
		}
	}
	if(S2[0]=='0'){
		S2="0";
	}
	cout<<S2;
	return 0;
}
