#include<bits/stdc++.h>
using namespace std;

const int N=1e+5;
int c[N+10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	cin>>a;
	
	int b=0;
	bool flag=0;
	while(flag==0){
		if(a[b]!='a'&&a[b]!='b'&&a[b]!='c'&&a[b]!='d'&&a[b]!='e'&&a[b]!='f'&&a[b]!='g'&&a[b]!='h'&&a[b]!='i'&&a[b]!='j'&&a[b]!='k'&&a[b]!='l'&&a[b]!='m'&&a[b]!='n'&&a[b]!='o'&&a[b]!='p'&&a[b]!='q'&&a[b]!='r'&&a[b]!='s'&&a[b]!='t'&&a[b]!='u'&&a[b]!='v'&&a[b]!='w'&&a[b]!='x'&&a[b]!='y'&&a[b]!='z'){
			if(a[b]!='0'&&a[b]!='1'&&a[b]!='2'&&a[b]!='3'&&a[b]!='4'&&a[b]!='5'&&a[b]!='6'&&a[b]!='7'&&a[b]!='8'&&a[b]!='9'){
				flag=1;
			}
		}
		b++;
	}
	
	int j=0;
	for(int i=0;i<=b;i++){
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			j++;
			c[j]=a[i]-'0';
		}
	}
	
	sort(c+1,c+j+1);
	for(int i=j;i>=1;i--){
		cout<<c[i];
	}


	return 0;
}
