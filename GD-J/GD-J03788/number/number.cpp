#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
char a[N];
int b[15];
//char c[6]={'0','e','6','2','4','5'};
void find(char s){
	if(s=='0')b[0]++;
	else if(s=='1')b[1]++;
	else if(s=='2')b[2]++;
	else if(s=='3')b[3]++;
	else if(s=='4')b[4]++;
	else if(s=='5')b[5]++;
	else if(s=='6')b[6]++;
	else if(s=='7')b[7]++;
	else if(s=='8')b[8]++;
	else if(s=='9')b[9]++;
}
int main(){
	freopen("number.cpp","r",stdin);
	freopen("number.cpp","w",stdout);
	for(int i=1;i<=N;i++){
		a[i]=getchar();
		//cout<<a[i];
		if(a[i]=='\0')break;
		find(a[i]); 
	}
	/*for(int i=1;i<=10;i++){
		find(c[i]);
		cout<<1;
	}*/
	for(int i=9;i>=0;i--){
		for(int j=b[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
} 
