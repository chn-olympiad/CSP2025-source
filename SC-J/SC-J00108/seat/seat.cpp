#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int score[n*m];
	for(int i=0;i<n*m;i++) cin>>score[i];
	int temp=score[0];
	for(int i=0;i<n*m-1;i++){
		bool check=false;
		for(int j=i;j<n*m-i-1;j++){
			if(score[j]<score[j+1]){
				swap(score[j],score[j+1]);
				check=true;
			}
		}
		if(check==false) break;
	}
	int a=1,b=1;
	for(int i=0; ;i++){
		if(temp==score[i]) break;
		else{
			if(b==m&&a%2==1) a++;
			else if(b==1&&a%2==0) a++;
				else{
					if(a%2==1) b++;
					else b--;
				}
		}
	}
	cout<<a<<" "<<b<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}