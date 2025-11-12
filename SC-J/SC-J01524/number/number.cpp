#include<bits/stdc++.h>
using namespace std;

char s[1000000];
int num[10]={0};
int full_long = 0;
int maxv[1000000] = {-1};
int now[1000000] = {-1};
int now_long=0;
bool compare(){
	int i=1;
	while(maxv[i]!= -1 && now[i]!= -1){
		//cout<<maxv[i]<<" "<<now[i]<<endl;
		if (maxv[i]<now[i]){
			return true;
		}else if (maxv[i] == now[i]){
			i++;
		}else{
			return false;
		}
	}
	
	if (maxv[i]!=1){
		return true;
	}else{
		return false;
	}
	
}
void search(int k)
{
	if (k>full_long){
		//printf("NOW:%lld,BIGGEST:%lld\n",now,maxv);
		// If true, maxv smaller or same. 
		if (compare() == true){
			int i=1;
			for (; i<=now_long ; i++){
				maxv[i] = now[i];
				
			}
			//cout<<now[i]<<" "<<k<<endl;
			//cout<<endl;
			maxv[full_long+1] = -1;
		}
		return;
	}
	for (int i=0;i<=9;i++){
		if (i==0 && k==1){
			continue;
		}
		if (num[i]>0){
			num[i]--;
			now[k] = i;
			now_long++;
			//printf("Message from XXX: runs %d times, num[i] is %d, now is %lld, i is %d\n",k,num[i],now,i);
			//printf("INPUT k=%d now=%lld\n",k+1,now*10+i);
			search(k+1);
			num[i]++;
			now[k] = -1;
			//now_long--;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int strlong = strlen(s);
	if(strlong == 1){
		cout<<s[0]-'0';
		return 0;
	} 
	for (int i=0;i<strlong;i++)
	{
		if (0<=s[i]-'0' && s[i]-'0'<=9){
			num[s[i]-'0']++;
			full_long++;
		}
	}
	//printf("Before Hard Searching %d\n",full_long);
	search(1);
	//	cout<<now_long<<endl;
	for (int i=1;maxv[i]!=-1;i++){
		cout<<maxv[i];
	}
	return 0;
}

/*
Fail Mountain

bool beforeno = false;
for (int j=i+1;j<=full_long;j++){
if ((now[j]!=-1) && beforeno == false){
continue;
}else{
if (beforeno == false){
now_long = j;
}
beforeno = true;
now[j] = -1;
}
}

now_long = i;
*/