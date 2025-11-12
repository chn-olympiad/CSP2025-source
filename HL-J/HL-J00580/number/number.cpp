#include<fstream>
using namespace std;
ifstream cin("number.in");
ofstream cout("number.out");
int main(){
	char s[1000]={},a[1000]={};
	int l=0;
	cin>>s;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[l]=s[i];
			l++;
		}
	}int index=0;
	for(int i=0;i<l;i++){
		while(a[index]<a[index+1]){
			char k=a[index];
			a[index]=a[index+1];
			a[index+1]=k;
			index++;
		}
		index=i;
	}
	for(int i=0;i<l;i++){
		cout<<a[i];
	}
	cin.close();
	cout.close();
	return 0;
}