#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	vector<int> score(n*m+1);
	for(int i=0;i<n*m;i++){
		cin>>score[i];
	}
	
	int flag=score[0];
	sort(score.begin(),score.end()-1,cmp);
	
	for(int i=0;i<n*m;i++){
		if(flag==score[i]){
			flag=i+1;
			break;
		}
	}
	if(flag%n==0){		
		cout<<flag/n<<" "<<m;
	}
	else if(flag/n%2==0){
		cout<<flag/n+1<<" "<<flag%n;
	}
	else{
		cout<<flag/n+1<<" "<<m-flag%n+1;
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
