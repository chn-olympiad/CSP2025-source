#include<bits/stdc++.h>
using namespace std;
int main(){
//#Shang4Shan3Ruo6Shui4
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char n[100010];
	int a[101010],i=0,j=0,sum=0;
	cin>>n;
	while(n[i]!='\0'){
		if(n[i]>='0'&n[i]<='9'){
			j++;
			a[j]=n[i]-'0';
		}
		i++;
	}
	for(int i=1;i<=j;i++){
		for(int z=1;z<=j-i;z++){
			if(a[z]<a[z+1]){
				int t=a[z];
				a[z]=a[z+1];
				a[z+1]=t;
			}
		}
	}
	if(j>10){
		for(int i=1;i<=j;i++){
			cout<<a[i];
		}
	}
	else {
		for(int i=1;i<=j;i++){
			sum=sum*10+a[i];
		}
		cout<<sum;
	}

	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
