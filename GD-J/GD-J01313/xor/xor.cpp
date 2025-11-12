#include<bits/stdc++.h>
using namespace std;
int Ans_xor[5005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	long long nnn,kkkk,flag00=1,flag11=1,oppp=0;
	cin>>nnn>>kkkk;
	for(int i=1;i<=nnn;i++)cin>>Ans_xor[i],flag11=(flag11&&(Ans_xor[i]==1)),flag00=(flag00&&(Ans_xor[i]==0)),oppp+=(Ans_xor[i]==1);
	if(flag00||flag11){
		if(kkkk==0){
			if(flag00&&flag11){
				long long ANSs=0,pree=0;
				for(int i=1;i<=nnn;i++){
					if(Ans_xor[i]==0)ANSs++,pree=0;
					else{
						if(pree==1)ANSs++,pree=0;
						else pree=1;
					}
				}
				cout<<ANSs<<"\n";
			}else if(flag00)cout<<nnn<<"\n";
			else cout<<nnn/2<<"\n";
		}else cout<<oppp<<"\n";
	}
	else{
		long long nowsum=0,cnttt=0;
		for(int i=1;i<=nnn;i++){
			nowsum^=Ans_xor[i];
			if(nowsum==kkkk)cnttt++,nowsum=0;
		}
		cout<<cnttt<<"\n";
	}
	return 0;
}
