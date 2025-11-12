#include <bits/stdc++.h>
using namespace std;
struct Node{
	long long Id,Num;
}Stu[105];
long long N,M;
long long Mp[15][15];
bool Cmp(Node X,Node Y){return X.Num>Y.Num;}
bool JI(long long X){
	if(X%2==1)return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>N>>M;
	for(int i=1;i<=N*M;i++){
		cin>>Stu[i].Num;
		Stu[i].Id=i;
	}
	sort(Stu+1,Stu+N*M+1,Cmp);
	long long H=1,L=1;
	if(Stu[1].Id==1){
		cout<<"1 1";
		return 0;
	}
	for(int i=2;i<=N*M;i++){
		if(H==N&&JI(L)){
			L++;
		}else if(H==1&&!JI(L)){
			L++;
		}else if(JI(L)){
			H++;
		}else if(!JI(L)){
			H--;
		}
		if(Stu[i].Id==1){
			cout<<L<<" "<<H;
			return 0;
		}
	}
	return 0;
} 
