#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string num;
char num_[100010];
long long idx;

bool cmp(char a,char b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>num;
	idx = 0;
	for(int i =0;i<num.size();i++){
		if(int(num[i])>=65 && int(num[i])<=90 || int(num[i])>=97 && int(num[i])<=122){
			continue;
		}else{
			num_[idx++] = num[i];
		}
	}
	sort(num_,num_+idx,cmp);
	cout<<num_;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
