#include<bits/stdc++.h>
using namespace std;

int q[10086];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int z=0,a=0,w=0;
	int s;
	cin>>s;
	for(int i=1;i<=10086;i++){
		if(s/10==0&&s%10==0){
			break;
		}else{
			q[i]=s%10;
			s=s/10;
			a++;
		}
		
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=a;j++){
			if(q[i]>q[j]){
				z=q[i];
				q[i]=q[j];
				q[j]=z;
			}
		}
	}
	for(int i=1;i<=a;i++){
		cout<<q[i];
	}
	
	
	fclose(stdin);
	fclose(stdout);
}
