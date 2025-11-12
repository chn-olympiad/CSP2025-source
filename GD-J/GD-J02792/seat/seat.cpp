#include<bits/stdc++.h>
using namespace std;
struct Student{
	int fen;
	bool IS_R;
}arr[10000];
int n,m,cnt=0;
bool cmp(Student a,Student b){
	return a.fen>b.fen;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	arr[1].IS_R=true;
	for(int i=1;i<=n*m;i++){
		int temp;
		cin>>temp;
		arr[i].fen=temp;
	}
	sort(arr+1,arr+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(arr[i].IS_R){
			cnt=i;
			break;
		}
	}
	int x=1,y=1,d=1;
	for(int i=2;i<=cnt;i++){
		if(x<n && d==1){
			x++;
		}
		else if(x==n && d==1){
			y++;
			d=2;
		}
		else if(x<=n && d==2 && x>1){
			x--;
		}
		else if(x==1 && d==2){
			y++;
			d=1;
		}
	}
	cout<<y<<" "<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
