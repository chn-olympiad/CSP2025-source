#include<fstream>
#include<string> 
#include<algorithm>

using namespace std;

ifstream cin("number.in");
ofstream cout("number.out"); 
int a[1000010];

int main(){
	string x;
	int n=1;
	cin >>x;
	int len=x.size();
	for(int i=0;i<len;i++){
		if(x[i]>='0'&&x[i]<='9'){
			a[n]=x[i]-'0';	
			n++;
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--){
		cout<<a[i];
	}
	return 0;
}
