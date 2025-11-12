#include<bits/stdc++.h>

using namespace std;

int t;
int seed;
int OUT[10];

int sj(int seed){
	unsigned int c = pow(2,31);
	return (seed*213014+251101) % c;
}

int club(){
	//date
	int n = 0;
	int MAX = 0;
	int CA[100100];
	int CB[100100];
	int CC[100100];
	int CM[100100];
	int used[100100];
	int AI = 0,BI = 0,CI = 0;
	int id = 0;
	int OA = 0,OB = 0,OC = 0;
	
	//reset
	for(int i = 0 ; i < 100100 ; i++){
		CA[i] = 0;
		CB[i] = 0;
		CC[i] = 0;
		CM[i] = 0;
		used[i] = 0;
	}
	
	//in
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> CA[i];
		cin >> CB[i];
		cin >> CC[i];
		CM[i] = max(max(CA[i],CB[i]),CC[i]);
	}
	for(int i = 0 ; i < n ; i++){
		MAX = INT_MIN;
		for(int j = 0 ; j < n ; j++){
			if(CM[j]>MAX && !used[j]){
				id = j;
				MAX = CM[j];
			}
		}//cout << id << "\n";
		if(max(max(CA[id],CB[id]),CC[id])==CA[id]&&AI<n/2){
			//cout << id << " to A\n";
			AI++;
			used[id] = true;
			OA += CA[id];
		}else if(max(max(CA[id],CB[id]),CC[id])==CB[id]&&BI<n/2){
			//cout << id << " to B\n";
			BI++;
			used[id] = true;
			OB += CB[id];
		}else if(max(max(CA[id],CB[id]),CC[id])==CC[id]&&CI<n/2){
			//cout << id << " to C\n";
			CI++;
			used[id] = true;
			OC += CC[id];
		}
	}
	
	return OA+OB+OC;
}

int main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	
	seed = 67109;
	
	for(int i = 0 ; i < t ; i++){
		OUT[i] = club();
	}
	for(int i = 0 ; i < t ; i++){
		cout << OUT[i] << "\n";
	}
	
	return 0;
}
