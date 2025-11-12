#include<fstream>
#include<algorithm>

using namespace std;

ifstream cin("seat.in");
ofstream cout("seat.out");
int a[110];

int main(){
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=n*m;i++){
		cin >>a[i];
	}
	int x=a[1],cnt=0;
	sort(a+1,a+n*m+1);
	int h=1,l=1;
	for(int i=n*m;i>=0;i--){
		//cout<<a[i]<<" "<<h<<" "<<l<<endl; 
		if(a[i]==x){
			break;
		}
		if(l%2==0){
			if((h-1)==0){
				h=1;
				l++;
			}else{
				h--;
			}	
		}else{
			if((h+1)>n){
				l++;
				h=n;
			}else{
				h++;
			}
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
