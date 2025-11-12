#include<iostream>
using namespace std;
const int WYNN_MAXN_SIZE=5*1e5+5;
int Input_Array[WYNN_MAXN_SIZE],count_ans;
struct Arrayment{//区块 
	int Left;
	int Right;
}Maybe_Answer[WYNN_MAXN_SIZE];//记录每个可行区块 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>Input_Array[i];
	for(int i=1;i<=n;i++){//分离以每个可行下标为起始的最小区块 
		if(Input_Array[i]==k){
			Maybe_Answer[++count_ans].Left=i,Maybe_Answer[count_ans].Right=i;
			continue;
		}
		int temp=Input_Array[i];
		for(int j=i+1;j<=n;j++){
			temp^=Input_Array[j];
			if(temp==k){
				Maybe_Answer[++count_ans].Left=i,Maybe_Answer[count_ans].Right=j;
				break;
			}
		}
	}
	int temp_maxn,answer_wynn=0;
	for(int i=1;i<=count_ans;i++){//dp我不会写，我枚举 
		temp_maxn=1;
		for(int j=i;j<count_ans;j++)
			if(Maybe_Answer[j].Right<Maybe_Answer[j+1].Left)temp_maxn++;
		if(temp_maxn>answer_wynn)answer_wynn=temp_maxn;
	}
	cout<<answer_wynn<<'\n';
	return 0;
}
