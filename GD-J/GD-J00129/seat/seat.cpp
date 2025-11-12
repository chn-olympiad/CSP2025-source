#include<iostream>
#include<vector>
#include<algorithm>
#include<windows.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int q=n*m;
	vector<int> a(q);
	for(int i=0;i<q;i++){
		cin>>a[i];
	}int r=a[0];
	sort(a.begin(),a.end(),greater<int>());
	int x=0,y=0;
	//  ÐÐ  ÁÐ 
	int k=1;
	while(q--){
		
		x+=k;
		if(x==n||x==-1){
			k=-k;
			x+=k;
			y++;
		}
		if(a[n*m-q]==r){
			cout<<y+1<<" "<<x+1<<endl;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
