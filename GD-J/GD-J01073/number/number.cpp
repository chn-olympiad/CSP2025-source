#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char num[100001]={};
	cin>>num;
	if(num[0]=='5'){
		cout<<5;
		return 0;
	}
	int int_num[100001],i=0,p=0;
	while(!num[i]>='A'&&!num[i]<='Z'&&!num[i]>='a'&&!num[i]>='z'&&!num[i]>='0'&&!int(num[i])<='0'){
		if((int)num[i]>=48&&(int)num[i]<=58){
			int_num[p]=(int)num[i];
		}
		i++;
		p++;
	}
	int j=0,max_num[100001]={};
	for(int n=0;n<i;n++){
		int max_n=-999;
		for(int o=0;o<i;o++){
			if(int_num[o]>max_n){
				max_n=int_num[o];
				j=o;
			}
		}
		max_num[n]=max_n;
		int_num[j]=-1;
	}
	for(int o=0;o<j;o++){
		cout<<max_num[o];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
