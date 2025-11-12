#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int wd,hg;
	cin>>wd>>hg;
	string s;
	int tgt;
	cin>>tgt;
	bool scoren[101];
	string score="";
	while(true){
		char a;
		scanf("%c",&a);
		if (a == '\n' || a==EOF){
			if (score != ""){
				int tmp = stoi(score);
				score = "";
				scoren[tmp] = true;
			}
			break;
		}else if(a == ' '){
			if (score != ""){
				int tmp = stoi(score);
				score = "";
				scoren[tmp] = true;
			}
		}else if('0'<=a and a<='9'){
			score += a;
		}
	} 
	int sum=0;
	scoren[tgt] = true;
	for(int i=100;i>=0;i--){
		if(scoren[i]== true){
			sum++;
			if(i==tgt){
				//cout<<sum<<"   ";
				cout<<ceil(double(sum)/double(hg)*1.00)<<" ";
				
				if (int(ceil(double(sum)/double(hg)*1.00))%2 ==0){
					if ((sum%hg)!=0){
						cout<<(hg-(sum%hg))+1;
					}else{
						cout<<1;
					}
					
				}else{
					if(sum%hg !=0){
					cout<<sum%hg;
					}else{
					cout<<hg;
					}
				}
			}
		}
	}
	return 0;
}
