#include<bits/stdc++.h>
using namespace std;
string s;
char b[1000];
int sum=0,hu=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int num=s.size();
	for(int i=0;i<=num;i++){
		if(s[i]>='0' && s[i]<='9'){
			sum++; 
			b[sum]=s[i]; 
		}
	}
	char max='0';
	int nrm=sum;
	while(sum--){
		for(int i=1;i<=num;i++){
			if(b[i]>max){
				max=b[i];
				hu=i;
		    }
	    }
	    b[hu]=-1;
	    cout<<max;
		max='0';
	}
	fclose(stdin);
	fclose(stdout);		
	return 0;
}
