#include <bits/stdc++.h>
using namespace std;
string s;
int nums[100009];
int numsne[100009];
int q=1;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	int pla=1;
	int mark=9;
	int len=s.size();
	for (int i=0;i<len;i++){
		if (s[i]>='0'&&s[i]<='9'){
			 nums[q]=int(s[i]-48);
			 q++;
		}
	}
	while (mark>-1){
		for (int i=1;i<=q;i++){
			if (nums[i]==mark){
				numsne[pla]=nums[i];
				pla++;
			} 
		}
		mark--;
	}
	for (int i=1;i<q;i++){
		cout<<numsne[i];
	}
	return 0;
}
