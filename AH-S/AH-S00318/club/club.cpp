#include<bits/stdc++.h>
using namespace std;

struct stu{
	int x, y, z;
}a[100005], q[100005], s1[100005], s2[100005], s3[100005];

struct num{
	int sum, cnt;
}c1, c2, c3;

int t, n, nsum = 1, sum1 = 1, sum2 = 1, sum3 = 1, ssum = 1;

bool cmp1(stu k, stu g){
	if(k.x < g.x){
		return true;
	}
	return false;
}

bool cmp2(stu k, stu g){
	if(k.y < g.y){
		return true;
	}
	return false;
}

bool cmp3(stu k, stu g){
	if(k.z < g.z){
		return true;
	}
	return false;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--){
		nsum = 1, sum1 = 1, sum2 = 1, sum3 = 1, ssum = 1;
		memset(a, 0, sizeof(a));
		memset(q, 0, sizeof(q));
		memset(s1, 0, sizeof(s1));
		memset(s2, 0, sizeof(s2));
		memset(s3, 0, sizeof(s3));
		c1 = {0, 0};
		c2 = {0, 0};
		c3 = {0, 0};
		cin>>n;
		for(int i = 1; i <= n; i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i = 1; i <= n; i++){
			if(a[i].x > a[i].y && a[i].x > a[i].z){
				c1.cnt++;
				c1.sum += a[i].x;
				s1[sum1] = a[i];
				sum1++;
			}else if(a[i].y > a[i].x && a[i].y > a[i].z){
				c2.cnt++;
				c2.sum += a[i].y;
				s2[sum2] = a[i];
				sum2++;
			}else if(a[i].z > a[i].y && a[i].z > a[i].x){
				c3.cnt++;
				c3.sum += a[i].z;
				s3[sum3] = a[i];
				sum3++;
			}else if(a[i].x == a[i].y && a[i].x != a[i].z){
				if(c1.cnt < c2.cnt){
					c1.cnt++;
					c1.sum += a[i].x;
					s1[sum1] = a[i];
					sum1++;
				}else if(c2.cnt < c1.cnt){
					c2.cnt++;
					c2.sum += a[i].y;
					s2[sum2] = a[i];
					sum2++;
				}else{
					q[nsum] = a[i];
					nsum++;
				}
			}else if(a[i].x == a[i].z && a[i].x != a[i].y){
				if(c1.cnt < c3.cnt){
					c1.cnt++;
					c1.sum += a[i].x;
					s1[sum1] = a[i];
					sum1++;
				}else if(c3.cnt < c1.cnt){
					c3.cnt++;
					c3.sum += a[i].z;
					s3[sum3] = a[i];
					sum3++;
				}else{
					q[nsum] = a[i];
					nsum++;
				}
			}else if(a[i].z == a[i].y && a[i].z != a[i].x){
				if(c3.cnt < c2.cnt){
					c3.cnt++;
					c3.sum += a[i].z;
					s3[sum3] = a[i];
					sum3++;
				}else if(c2.cnt < c3.cnt){
					c2.cnt++;
					c2.sum += a[i].y;
					s2[sum2] = a[i];
					sum2++;
				}else{
					q[nsum] = a[i];
					nsum++;
				}
			}else{
				q[nsum] = a[i];
				nsum++;
			}
		}
		for(int i = 1; i < nsum; i++){
			if(q[i].x == q[i].y && q[i].x != q[i].z){
				if(c1.cnt < c2.cnt){
					c1.cnt++;
					c1.sum += q[i].x;
					s1[sum1] = q[i];
					sum1++;
				}else if(c2.cnt < c1.cnt){
					c2.cnt++;
					c2.sum += q[i].y;
					s2[sum2] = q[i];
					sum2++;
				}else{
					c1.cnt++;
					c1.sum += q[i].x;
					s1[sum1] = q[i];
					sum1++;
				}
			}else if(q[i].x == q[i].z && q[i].x != q[i].y){
				if(c1.cnt < c3.cnt){
					c1.cnt++;
					c1.sum += q[i].x;
					s1[sum1] = q[i];
					sum1++;
				}else if(c3.cnt < c1.cnt){
					c3.cnt++;
					c3.sum += q[i].z;
					s3[sum3] = q[i];
					sum3++;
				}else{
					c3.cnt++;
					c3.sum += q[i].z;
					s3[sum3] = q[i];
					sum3++;
				}
			}else if(q[i].z == q[i].y && q[i].z != q[i].x){
				if(c3.cnt < c2.cnt){
					c3.cnt++;
					c3.sum += q[i].z;
					s3[sum3] = q[i];
					sum3++;
				}else if(c2.cnt < c3.cnt){
					c2.cnt++;
					c2.sum += q[i].y;
					s2[sum2] = q[i];
					sum2++;
				}else{
					c2.cnt++;
					c2.sum += q[i].y;
					s2[sum2] = q[i];
					sum2++;
				}
			}else{
				c2.cnt++;
				c2.sum += q[i].y;
				s2[sum2] = q[i];
				sum2++;
			}
		}
		while(c1.cnt > n/2 || c2.cnt > n/2 || c3.cnt > n/2){
			sort(s1 + 1, s1 + n + 1, cmp1);
			int i = 1;
			while(c1.cnt > n/2){
				c1.cnt--;
				c1.sum -= s1[i].x;
				if(s1[i].y > s1[i].z){
					s2[sum2] = s1[i];
					sum2++;
				}else{
					s3[sum3] = s1[i];
					sum3++;
				}
				i++;
			}
			i = 1;
			sort(s2 + 1, s2 + n + 1, cmp2);
			while(c2.cnt > n/2){
				c2.cnt--;
				c2.sum -= s2[i].y;
				if(s2[i].x > s2[i].z){
					s3[sum3] = s2[i];
					sum3++;
				}else{
					s1[sum3] = s2[i];
					sum1++;
				}
				i++;
			}
			i = 1;
			sort(s3 + 1, s3 + n + 1, cmp3);
			while(c3.cnt > n/2){
				c3.cnt--;
				c3.sum -= s1[i].z;
				if(s3[i].x > s3[i].y){
					s1[sum3] = s3[i];
					sum1++;
				}else{
					s2[sum3] = s3[i];
					sum2++;
				}
				i++;
			}
		}
		cout<<c1.sum<<" "<<c2.sum<<" "<<c3.sum<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
