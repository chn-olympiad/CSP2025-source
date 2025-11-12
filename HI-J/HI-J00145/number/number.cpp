#include<bits/stdc++.h>
using namespace std;
char s[1000010];
vector<int>answ;
int SizeOfS(){
	int x=0;
	while(++x){
		if(s[x]==-1)return x--;
	}
}
int intChange(char x){
	if(x=='0')return 0;
	else if(x=='1')return 1;
	else if(x=='2')return 2;
	else if(x=='3')return 3;
	else if(x=='4')return 4;
	else if(x=='5')return 5;
	else if(x=='6')return 6;
	else if(x=='7')return 7;
	else if(x=='8')return 8;
	else if(x=='9')return 9;
}//[Warning] control reaches end of non-void function [-Wreturn-type]
void findDigits(){
	int S=SizeOfS();
	for(int i=0;i<=S;i++){
		if(s[i]>='0'&&s[i]<='9'){
			//cout<<intChange(s[i])<<" ";/////
			int f=intChange(s[i]);
			answ.push_back(f);
		}
	} 
}

int main(){//114514
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(!answ.empty())answ.pop_back();
	for(int i=1;i<=1000010;i++)s[i]=-1;
	gets(s);
	findDigits();
	int Sa=answ.size();
	for(int j=1;j<=Sa;j++){
		for(int i=0;i<Sa-1;i++){
			if(answ[i]<=answ[i+1]){
				int m;
				m=answ[i];
				answ[i]=answ[i+1];
				answ[i+1]=m;
			}
		}
	}//sort
	for(int i=0;i<Sa;i++){
		cout<<answ[i];
	}
	return 0;
}
/*vector<int>answ;
vector<char>s;*/
	/*while(!answ.empty())answ.pop_back();
	while(!s.empty())s.pop_back();
	while(1){
		char X;
		scanf("%c",&X);
		if('0'<=X&&X<='9')s.push_back(X);
		else if ('a'<=X&&X<='z')s.push_back(X);
		else break;
	}//cin s
	findDigits();
	int S=answ.size();
	//for(int i=0;i<S;i++)cout<<answ[i]<<" ";/////
	//cout<<endl;//////
	answ.pop_back();//??//
	for(int i=0;i<S;i++){
		for(int i=0;i<S-1;i++){
			if(answ[i]<=answ[i+1]){
				int x=answ[i];
				answ[i]=answ[i+1];
				answ[i+1]=x;
			}//ÅÅÐò 
		}	
	}//sort(answ+1,answ+1+S);////
	//cout<<answ.size()<<endl;////
	//for(int i=0;i<S;i++)cout<<answ[i];////
	cout<<endl;////
	for(int i=0;i<S;i++)cout<<answ[i];*/
