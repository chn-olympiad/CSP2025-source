#include<fstream>
#include<map>
#include<string>
#include<string.h> 
using namespace std;
ifstream cin("replace.in");
ofstream cout("replace.out");
map<string,string>A;//替换 
map<string,int>cnt_A;//计数 
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i=0;i<n;i++){
		string x,y;
		cin >> x >> y;
		A[x]=y;
		cnt_A[x]++;
	}
	for(int i=0;i<q;i++){
		string x,y;
		cin >> x >> y;
		int starti=0,endi=0;
		int t=0;//不再改变start 
		for(int d=0;d<x.size();d++){
			if(x[d]!=y[d]&&t==0){
				starti=d;
				t=1;
				
			}
			if(x[d]!=y[d])endi=d;
		}
		long long sum=0;
//		cout << starti << " " << endi << endl;
		for(int x1=0;x1<=starti;x1++){
			for(int y1=endi;y1<x.size();y1++){
				string tempx=x.substr(x1,y1-x1+1);
				string tempy=y.substr(x1,y1-x1+1);
//				cout << tempx << " ";
				if(A[tempx]==tempy)sum+=cnt_A[tempx];
//				cout << tempx << " ";
			}
		}
		cout << sum;
		cout << endl;
	}
	cin.close();
	cout.close();
	return 0;
}
