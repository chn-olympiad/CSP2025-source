#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int ntyq,mtyq;
	cin >> ntyq >> mtyq;
	int wtyq=ntyq*mtyq;
	int atyq[wtyq+5];
	for(int ityq=1;ityq<=wtyq;ityq++){
		cin >> atyq[ityq]; 
	}
	int ltyq=atyq[1],styq;
	sort(atyq+1,atyq+wtyq+1);
	for(int ityq=1;ityq<=wtyq;ityq++){
		if(atyq[ityq]==ltyq){
			styq=ityq;
			break;
		}
	}
	styq=wtyq-styq+1;
	int btyq=styq/ntyq,ctyq=styq%ntyq;//2 1
	if(ctyq!=0){
		btyq+=1;
	}else{
		if(btyq%2==1){
			ctyq=ntyq;
			cout << btyq << " " << ctyq;
			return 0;
		}else{
			ctyq=1;
			cout << btyq << " " << ctyq;
			return 0;
		}
    }
	if(btyq%2==1){
		cout << btyq << " " <<  ctyq;
	}else{
		cout << btyq << " " << ntyq-ctyq+1;
	}
	return 0;
} 
