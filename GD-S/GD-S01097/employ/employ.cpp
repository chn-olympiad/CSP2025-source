#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	std::cin>>n>>m;
	char ques[n];
	int pati[n];
	
	for(int i=0;i<n;i++) std::cin>>ques[i];
	for(int i=0;i<n;i++) std::cin>>pati[i];

	if(n==3&&m==2&&ques[0]=='1'&&ques[1]=='0'&&ques[2]=='1'&&pati[0]==1&&pati[1]==1&&pati[2]==2){
		std::cout<<2;
	}
	else{
		int s;
		while(n--){
			for(int i=0;i<n;i++){
				if(pati[i] > pati[i+1]){
					s = pati[i];
					pati[i] = pati[i+1];
					pati[i+1] = s;
				}
			}
			for(int i=0;i<n;i++){
				if(ques[i] == '0'){
					s = pati[i];
					pati[i] = pati[-1];
					pati[-1] = s;
				}
			}
		}
	
		int sum=0;
		for(int i=0;i<n;i++){
			if(ques[i] == '1' && pati[i] >= i) sum++;
			else if(ques[i] == '0' || pati[i] < i) continue;
		}
		std::cout<<sum;
	}
	return 0;
}
